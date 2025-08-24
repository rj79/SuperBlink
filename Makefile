all: example_on_off example_bit_pattern example_manual example_neopixel

example_on_off:
	pio ci examples/on_off/on_off.ino --lib=. --project-conf=platformio.ini

example_bit_pattern:
	pio ci examples/bit_pattern/bit_pattern.ino --lib=. --project-conf=platformio.ini

example_manual:
	pio ci examples/manual/manual.ino --lib=. --project-conf=platformio.ini

example_sine:
	pio ci examples/manual/sine.ino --lib=. --project-conf=platformio.ini

example_neopixel:
	pio ci examples/neopixel/neopixel.ino --lib=. --project-conf=platformio.ini
