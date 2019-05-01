//Abdoul Raouf 
#define _XOPEN_SOURCE
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>
int main (int argc, string argv[])
{

    if(argc!=2)
    {
        printf("Usage: ./crack <hash\n");
        return 1;
    }
    // we have 26 lowercase + 26 uppercase lettre + the \0 so the total is=53
    const int alphabet=53;

    //write the possible letters we have
    string alphabet="\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash =argv[1];
    char salt [3];
    memcpy (salt, hash, 2);
    salt[2]='\0';
    char work_well[6]="\0\0\0\0\0\0";
    for (int fifth =0; fifth<alphabet;fifth++)
    {
        for(int fourth =0; fourth<alphabet;fourth++)
        {
            for(int third =0; third<alphabet;third++)
            {
                for (int second =0;second<alphabet;second++)
                {
                    for(int first =0; first<alphabet; first++)
                    {
                        work_well[0]=alphabet[first];
                        work_well[1]=alphabet[second];
                        work_well[2]=alphabet[third];
                        work_well[3]=alphabet[fourth];
                        work_well[4]=alphabet[fifth];
                        //to stop the looping when is  null hracter.
                        if (strcmp(crypt(work_well, salt), hash)==0)
                        {
                            printf("%s\n", work_well);
                            return 0;
                        }
                    }
                }
            }
        }
            printf("you can't have the password. crack again");

            return 2;
    }

}
