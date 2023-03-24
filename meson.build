project('elf2iso', 'cpp')

#########################
#  Configurable section #
#########################
version = '0.1.0'
bin_name = 'elf2iso'
################################
#  End of configurable section #
################################

libisofs = dependency('libisofs-1', required : true)

extra_args = ['-DVERSION=@0@'.format(version)]

inc_dir = include_directories('include/')

sources = [
  'src/main.cpp',
  'src/args.cpp'
]

elf2iso = executable(bin_name, sources,
  cpp_args : extra_args,
  dependencies : [libisofs],
  include_directories : inc_dir
)
