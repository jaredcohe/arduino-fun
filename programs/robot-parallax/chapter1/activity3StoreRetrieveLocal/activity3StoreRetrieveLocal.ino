/* http://learn.parallax.com/node/132
*/

void setup()
{
  Serial.begin(9600);
  int a = 42;
  char c = 'm';
  char n = 'n';
  char o = 'o';
  char p = 'p';
  byte c2 = 'm';
  float root2 = sqrt(2.0);
  
  Serial.println(a);
  Serial.println(c);
  Serial.println(c, DEC);
  Serial.println(n, DEC);
  Serial.println(o, DEC);
  Serial.println(p, DEC);
  Serial.println(c2);
  Serial.println(root2);
}

void loop()
{

}

