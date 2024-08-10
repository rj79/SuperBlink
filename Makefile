all: example_on_off example_bit_pattern example_manual

example_on_off:
	pio ci examples/on_off.cpp --lib=. --project-conf=platformio.ini

example_bit_pattern:
	pio ci examples/bit_pattern.cpp --lib=. --project-conf=platformio.ini

example_manual:
	pio ci examples/manual.cpp --lib=. --project-conf=platformio.ini
