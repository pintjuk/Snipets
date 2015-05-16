/*
converts integer to character array
for when itao is unavalable or unsafe

str sould point to where the string should be wrighten
len is the length of the string
val is the integer to be converted
ofset gets set to the position in str were miningful text starts
*/
void intToStr (char* str, const int len, int val, int* ofset)
{
  char i;
  bool neg=false;
  if(val <0){
      val = (~val)+1;
      neg=true;
  }
  for(i=2; i<=len; i++)
  {
    str[len-i] = (char) ((val % 10) + '0');
    val/=10;
  }
  for(i=0; i<len; i++)
  {
    if ('0'==str[i])
    {
        str[i]=' ';
    }
    else
    {
        if(neg)
            if(i-1>=0)
            {
                str[i-1]='-';
                (*ofset)=i-1;
            }
            else
            {
                str[0]='-';
                (*ofset)=0;
            }
        break;
    }
  }
  str[len] = '\0';
}
