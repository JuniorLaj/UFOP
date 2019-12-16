all:
	iverilog -o test teste.v
	python3 montador.py $(ARGS)
	vvp test
	rm -rf test

test: teste.v
	iverilog -o test teste.v

run: test
	python3 montador.py $(ARGS)
	vvp test

clean:
	rm -rf test
