#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystallcd(13, 12, 11, 10, 9, 8);  

longfirst = 0;
longsecond = 0;
doubleresult = 0;
intposition = 0 ;
char customKey;
constbyte ROW = 4;
constbyte COLUMN = 4;
char operation =' ';

char keys[ROW][COLUMN] = {
  {'1','2','3','/'},
  {'4','5','6','*'},
  {'7','8','9','-'},
  {'C','0','=','+'}
};
byterowPins[ROW] = {7 ,6 ,5 ,4};
bytecolPins[COLUMN] = {3, 2, 1, 0};

KeypadcustomKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROW, COLUMN); // classKeypadinstanceinitialization

void setup(){
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("Czyzewska");
lcd.setCursor(0,1);
lcd.print("Dabrowska");
delay(1500);
lcd.clear(); 
}
voidloop()
{
customKey = customKeypad.getKey();
switch(customKey) 
  {
case '0' ... '9': 

if(operation==' '){
lcd.setCursor(0,0);
first = first * 10 + (customKey - '0');
lcd.print(first);
position++;
  }
else{
lcd.setCursor(position,0);
second=second * 10 +(customKey - '0');
lcd.print(second);

    }
break;

case '+':
if(operation==' '){
operation='+';
lcd.print("+");
position++;
    }
break;

case '-':
if(operation==' '){
operation='-';
lcd.print("-");
position++;
    }
break;

case '*':
if(operation==' '){
operation='*';
lcd.print("*");
position++;
    }
break;

case '/':
if(operation==' '){
operation='/';
lcd.print("/");
position++;
    }
break;

case 'C':
result = 0;
first = 0;
second = 0;
position = 0;
operation=' ';
lcd.clear();
break;

case '=':
if (operation=='+')
    {
result = first + second;
lcd.setCursor(1,1);
lcd.print(result);
operation=' ';
    }

if (operation=='-')
    {
result = first - second;
lcd.setCursor(1,1);
lcd.print(result);
operation=' ';
    }

if (operation=='*')
    {
result = first * second;
lcd.setCursor(1,1);
lcd.print(result);
operation=' ';
    }

if (operation=='/')
    {
if (second!=0)
      {
result = first / second;
lcd.setCursor(1,1);
lcd.print(result);
operation=' ';
      }

else
      {
lcd.setCursor(1,1);
lcd.print("ERROR");
      }


    }

  }
}


