#include <gocpp.cc>

int main() {
  usize memorySize = 10 * 1024 * 1024;
  uint8* memory = (uint8*)malloc(memorySize);

  allocator::BumpAllocator allocator;
  allocator::Init(&allocator, memory, memorySize);

  var result = strings::Join(allocator, STR("Hello "), STR("Steve!"));
  fmt::Println(STR("{}{}"), result[0], result[13]);
  return 0;
}
