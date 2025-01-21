all: 2020 2022 2023 2024

.PHONY: 2020
2020:
	cd src/2020; make

.PHONY: 2022
2022:
	cd src/2022; make

.PHONY: 2022-tests
2022-tests:
	cd src/2022; make tests

.PHONY: 2023
2023:
	cd src/2023; make main

.PHONY: 2023-tests
2023-tests:
	cd src/2023; make tests

.PHONY: 2024
2024:
	cd src/2024; make main

.PHONY: 2024-tests
2024-tests:
	cd src/2024; make tests
