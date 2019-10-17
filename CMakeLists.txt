cmake_minimum_required(VERSION 3.13)
project(CIS3050-A2-code)

set(CMAKE_CXX_STANDARD 14)

add_executable(CIS3050-A2-code formatter_main.c formatter_process.c strconcat.c strsplit.c module_api.h module_tools.h os_defs.h stringtools.h Modules/default/default.c Modules/caps/caps.c Modules/quote/quote.c Modules/CRLF/crlf.c Modules/bare/bare.c Modules/native/native.c)

target_link_libraries(CIS3050-A2-code ${CMAKE_DL_LIBS})