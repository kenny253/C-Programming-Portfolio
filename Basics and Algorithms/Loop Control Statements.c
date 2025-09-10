{
int x;
for ( x = 10; x > 5; x-- ) {
if ( x == 7 )
continue;
//break;
printf("\n%d\n", x);
} //end for loop
system("cls");
//this system clear program clears the display terminal where the finished code is displayed

//when break or continue is used at the end of the loop it only prints one number depending on its position in the loop.
return 0;
}
