project('client-debug', 'cpp',
  default_options: [
    'cpp_std=c++17',
    'buildtype=release',
    'optimization=2',
    'debug=false',
    'b_ndebug=if-release',
    'warning_level=3'
  ]
)

boost_dep=dependency('boost', method:'pkg-config')
spdlog_dep=dependency('spdlog', method:'pkg-config')

# Para windou boost necesita "Ws2_32.lib" y "wsock32"
if host_machine.system() == 'windows'
  win_args = ['-lws2_32', '-lwsock32']
else
  win_args = []
endif

executable('client-app',
  'src/main.cpp',dependencies:[boost_dep, spdlog_dep],link_args: win_args)