Para bom uso do montador e do programa verilog, é necessário considerar:

1 - Para executar o programa, basta digitar o seguinte código em terminal: " make all ARGS="nomeDoArquivoMIPS"" em que "nomeDoArquivoMIPS"é o nome do arquivo de entrada (em Assembly) que o programa em python irá criar um novo arquivo porém em binário.

2 - O formato da instrução MIPS, segue o padrão normal com exceção do "$" em cada registrador, por exemplo: "lw t0,5(t1)", ou "add t0,t1,52", ou "addi t0,t1,5".

3 - O arquivo verilog de TestBench, (que será compilado e executado pelo make), precisa ter o nome "teste.v", para bom funcionamento.

4 - O comando do primeiro passo executará tanto o programa em Python quanto o programa em verilog e depois excluirá o executado criado pela execução do verilog.
