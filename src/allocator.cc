#pragma once
#include <functional>

#include "types.cc"

namespace allocator {

struct Allocator {
  std::function<void*(usize)> Alloc;
};

struct BumpAllocator : Allocator {
  uint8* data;
  uint8* current;
  uint8* end;
};

void* BumpAllocator_Alloc(BumpAllocator* allocator, usize size) {
  void* result = allocator->current;

  usize alignment = 16;
  usize padding = (alignment - ((uintptr_t)result % alignment)) % alignment;

  uint8* newCurrent = allocator->current + size + padding;

  if (newCurrent > allocator->end) {
    return null;
  }

  allocator->current = newCurrent;
  return result;
}

void Init(BumpAllocator* allocator, uint8* data, usize size) {
  allocator->data = allocator->current = data;
  allocator->end = (uint8*)data + size;

  allocator->Alloc = [=](usize size) {
    return BumpAllocator_Alloc(allocator, size);
  };
}

} // namespace allocator
