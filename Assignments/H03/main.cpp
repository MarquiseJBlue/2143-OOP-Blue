void Hand::Sort(){

//for loops for sorting through the cards
for(int i=0;i<Size():i++)
{
  for(int j=1;j<Size()-1;j++)
  {
      //comparing two cards
      if(Cards[i]->rank>Cards[j+i]->rank)
      {
        
          cout <<"swapping\n;
          
          //swapping the actual positions being compared
          Card*temp=Cards[i];
          Cards[i]=Cards[j+i];
          Cards[j+i]=temp;
          }
     }
   }
}
