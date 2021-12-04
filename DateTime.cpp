
 #include<DateTime.h> 


void setup()
{
lcd.begin(16.2) // set up the LCD's number of rows and columns
DateTime.ync(812868312); // yearly time in seconds
}
void loop()
{
if(DateTime.available())
  {
     unsigned long prevtime = DateTime.now();
     while( prevtime == DateTime.now());
     DateTime.availabe(); // availabe date and time
     digitalClockDisplay(); // Displays digital clock
  }

}
void printDigits(byte digits) 
{
lcd.print(":");  // print out : on lcd
if (digits < 10)   // check if the  digit is less then 10 and if so print a 0
   lcd.print('0'); // print 0 on the lcd
   lcd.print(digits,DEC);
}
void digitalClockDisplay(){
 lcd.home();
 // digital clock display of current time
 lcd.print(DateTime.Hour,DEC);  
 printDigits(DateTime.Minute);  // print out date in minutes 
 printDigits(DateTime.Second);  // print out date time in seconds
}