    #include <stdio.h>
    int main()
    {
      char str[] = "012abc578";
      char sub[] = "ab";
      int i, j=0, k;
      for(i=0; str[i]; i++)
      {
        if(str[i] == sub[j])
        {
          for(k=i, j=0; str[k] && sub[j]; j++, k++)
            if(str[k]!=sub[j])
                break;
           if(!sub[j]){
            printf("Substring: %d %d %d\n", i, j, k);
            return 0;}
        }
      }
      printf("Not a substring\n");
     return 0;
    }