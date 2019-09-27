void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}


//Funçoes das Portas lógicas
//1 - AND
bool checkAnd (bool X, bool Y) {
  if (X==true && Y==true)
    return true;
    else
    return false;
}

//2 - OR
bool checkOr (bool X, bool Y) {
  if (X==true || Y==true)
    return true;
    else
    return false;
}

//3 - NAND
bool checkNand (bool X, bool Y) {
  if (X==true && Y==true)
    return false;
    else
    return true;
}

//4 - NOR
bool checkNor (bool X, bool Y) {
  if (X==true || Y==true)
    return false;
    else
    return true;
}

//5 - XOR
bool checkXor (bool X, bool Y) {
  if (X==true ^ Y==true)
    return true;
    else
    return false;
}

//6 - XNOR
bool checkXnor (bool X, bool Y) {
  if (X==true ^ Y==true)
    return false;
    else
    return true;
}

//Função para escolher qual porta lógica quer testar com
//valores booleanos dados
bool checking (int logicPort, bool X, bool Y) {
  switch(logicPort) {
    case 1:
    	checkAnd(X, Y);
    break;
    case 2:
    	checkOr(X, Y);
    break;
    case 3:
    	checkNand(X, Y);
    break;
    case 4:
    	checkNor(X, Y);
    break;
    case 5:
    	checkXor(X, Y);
    break;
    case 6:
    	checkXnor(X, Y);
    break;
  }
}

//Defina valores true or false para as lampadas vemelha e azul
//True para ligado e false para desligado
bool redValue = true;  //mude esse valor caso queira fazer um teste diferente
bool blueValue = true; //mude esse valor caso queira um teste diferente

//defina o teste que quer fazer: 1 para AND, 2 para OR, 3 para NAND, 4 para NOR, 5 para XOR e 6 para XNOR
int tipoDoTeste = 1; //mude esse valor caso queira um teste diferente
void loop()
{
  //Aqui passamos o valor para os LEDS vermelho e azul conforme os valores que foram selecionados
  //nas linhas 85 e 86
  digitalWrite(13, redValue);
  digitalWrite(12, redValue); 
 
  
  //Aqui testamos no LED verde a porta logica, baseada nas escolhas que foram feitas nas linhas
  //85, 86 e 89
  //caso o retorno seja verdadeiro, a luz verde ira piscar, caso falso vai permanecer apagada
  digitalWrite(11, checking(tipoDoTeste, redValue, blueValue));
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  
}