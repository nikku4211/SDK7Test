# The name of your project.
name = 'sdk7test'

bin2s = find_program('bin2s-py')

#files = custom_target('my-bin',
#  input: 'data/circle.bin',
#  output: ['circle.h', 'circle.s'],
#  command: [bin2s, '-H', '@OUTPUT0@', '-o', '@OUTPUT1@', '@INPUT@'])

# All of the source files used by your project.
sources = [
  'src/main.c', 
  
  'include/circle.s',
  'include/ballgers.s',
  'include/ponggers.s',
  'include/spritefont.s'
]

# All of the include directories used by your project.
includes = [
  'include',
]

# Linker arguments. Be careful with these.
# -Wl,-Map causes the linker to output a 'link map', which can be useful for
# debugging. If you don't know what that is, you can safely ignore it.
link_args = [
  f'-Wl,-Map,@name@.map',
]

# Dependencies. gba-meson provides a large number of GBA development libraries.
# Check them out and add the ones you want to use to this list.
dependencies = [
  dependency('minrt'),
  dependency('libseven')
]

# The main executable for your game. We give it a '.elf' file extension,
# just to make the file more easy to differentiate from a raw ROM.
elf = executable(
  name,
  sources,
  include_directories: includes,
  link_args: link_args,
  dependencies: dependencies,
  name_suffix: 'elf')

# Get the 'makerom' program from sdk-seven.
makerom = find_program('makerom')

# Build a raw GBA ROM file from your ELF file.
rom = custom_target(
  name + '_rom',
  input: elf,
  output: name + '.gba',
  command: [makerom, '@INPUT@', '@OUTPUT@'],
  build_by_default: true)
