all: 2020 2022

.PHONY: 2020
2020:
	cd src/2020; make

.PHONY: 2022
2022:
	cd src/2022; make

.PHONY: 2022-tests
2022-tests:
	cd src/2022; make tests
