Para bom uso do montador e do programa verilog, � necess�rio considerar:

1 - Para executar o programa, basta digitar o seguinte c�digo em terminal: " make all ARGS="nomeDoArquivoMIPS"" em que "nomeDoArquivoMIPS"� o nome do arquivo de entrada (em Assembly) que o programa em python ir� criar um novo arquivo por�m em bin�rio.

2 - O formato da instru��o MIPS, segue o padr�o normal com exce��o do "$" em cada registrador, por exemplo: "lw t0,5(t1)", ou "add t0,t1,52", ou "addi t0,t1,5".

3 - O arquivo verilog de TestBench, (que ser� compilado e executado pelo make), precisa ter o nome "teste.v", para bom funcionamento.

4 - O comando do primeiro passo executar� tanto o programa em Python quanto o programa em verilog e depois excluir� o executado criado pela execu��o do verilog.
