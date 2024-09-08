SERVICE_NAME = bootloader

OUTPUT_FILE = bootloader.bin

all: build run

build:
	docker-compose run --rm $(SERVICE_NAME)

run:
	qemu-system-x86_64 -drive format=raw,file=$(OUTPUT_FILE)

clean:
	rm -f $(OUTPUT_FILE)
