add_executable(br
        br.cpp
        )

pico_enable_stdio_usb(br 1)
pico_enable_stdio_uart(br 0)

target_link_libraries(br pico_stdlib pico_neopixel)

# create map/bin/hex file etc.
pico_add_extra_outputs(br)
