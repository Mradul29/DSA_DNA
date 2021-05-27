#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<bits/stdc++.h>
#include<strings.h>
using namespace std;

//functions used////
int page1();
int page2();
int page3();
void rundna();
void get1();
void get();
int check(char A11[], char A12[], int c);
void compare(char C11[], int a1, char D11[], int a2);
void kmpsearch(char p[], char t[], int m, int n);
void lps(char p[], int m, int l[]);

//////////// page 1///////////////
int page1()
{
int n;
cout<<"DNA COMPARISON ";
cout<<"\n1.About Us"<<endl<<"2.Instructions"<<endl<<"3.Run"<<endl<<"4.Exit"<<endl;
cout<<"Choose an option to proceed ";
cin>>n;
switch(n)
{
 int a;
case 1:
 a=page2();
 if(a==1)
 {
 page1();
 }
 else if(a==2)
 {
 return 0;
 }
 else
 cout<<"invalid input";
 break;
case 2:
 a=page3();
 if(a==1)
 page1();
 else if(a==2)
 return 0;
 else cout<<"invalidinput";
 break;
case 3:
 int t;
 rundna();
 break;
case 4:
 return 0;
default:
cout<<"Invalid input\n" ;
} 
return 0; 
}

//////////// page 2///////////////
int page2()
{
cout<<"\nAbout DNA comparision"; 
cout<<"first function::To check the percent matching of 2 DNA of same or different species"<<endl;
cout<<"second function::To check the percentage of characterstics present in the particular DNA";
cout<<endl<<"1.Main page"<<endl<<"2.Exit";
cout<<"\n Choose an option to proceed ";
int c;
cin>>c;
return c;
}

//////////// page 3///////////////

int page3()
{
cout<<"\nINSTRUCTIONS PAGE";
cout<<"\n INPUT:\n"<<"THE DNA MUST BE INPUTTED BASE BY BASE, EACH IN CAPITALS. THEY ARE STORED AS CHAHRACTER ARRAY, NOT AS STRING SOUSER MUST ENTER ONE BASE AT A TIME.\n";
cout<<"\n OUTPUT: \n"<<"\nIN THE COMPARING FUNCTION, WE COMPARE THE TWO INPUTTED DNAs AND OUTPUT THE PERCENTAGE OF DNAMATCHED."<<"\nFOR EXAMPLE IF THE OUTPUT SAYS 25% MATCH, IT MEANSTHAT 25% OF DNA 1 IS PRESENT IN DNA 2. HENCE THE SPECIES 2 WILL HAVE25% CHARACTERISTICS OF SPECIES 1.";
cout<<"\nIN THE MATCHING CHARACTERISTICS FUNCTION, WE FIND THE % OFTHE INPUT CHARACTERISTIC IN THE INPUT DNA."<<"\n FOR EXAMPLE IF WE SAY THAT THERE IS 20%MATCHING OF THE CHARACTERISTICS IN THE DNA,THEN WE CAN SAY THAT THE SPECIES HAS 20%OF THAT CHARACTERISTIC.";
cout<<endl<<"\n1.Main page"<<endl<<"2.Exit";
cout<<"\n Choose an option to proceed ";
int c;
cin>>c;
return c;
}

////////// run
void rundna()
{
    int k;
    cout<<"\n 1. To compare two DNAs and know how much similar they are";
    cout<<"\n 2. To check how much percentage of a given characteristics is present in a DNA";
    cout<<"\n Choose an option to proceed: ";
    cin>>k;
    switch(k)
    {
        case 1:
            get1();
            break;
        case 2:
            get();
            break;
        default:
            cout<<"\n Invalid Input";
    }
}

// get1//////
void get1(){
    int i, n1, n2, c1=0, c2=0, t1, t2;
    char A11[80], A12[80], B11[80], B12[80];
    cout<<"\n Enter the number of nodes in the DNA 1: ";
    cin>>n1;
    c1=n1*10;
    cout<<"\n Enter the first strand of the DNA 1: \n";
    
    for(i=0;i<c1;i++)
        cin>>A11[i];
    
    cout<<"\n Enter the second strand of the DNA 1: \n";
    
    for(i=0;i<c1;i++)
        cin>>A12[i];
        
    t1=check(A11,A12,c1);
    cout<<"\nEnter the number of nodes in the DNA 2: ";
    cin>>n2;
    cout<<"\n Enter the first strand of the DNA 2: \n";
    c2=n2*10;
    
    for(i=0;i<c2;i++)
        cin>>B11[i];
    
    cout<<"\n Enter the second strand of the DNA 2: \n";
    
    for(i=0;i<c2;i++)
        cin>>B12[i];
    
    t2=check(B11,B12,c2);
    if(t1==1)
    {
        cout<<"\n The first strand of the DNA 1 : \n ";
        for(i=0;i<c1;i++)
        {
            cout<<A11[i]<<"";
        }
        cout<<"\n The second strand of the DNA 1:\n ";
        for(i=0;i<c1;i++)
            cout<<A12[i]<<"";
    }
    if(t2==1){
        cout<<"\n The first strand of the DNA 2 : \n ";
        for(i=0;i<c2;i++)
            cout<<B11[i]<<"";
        
        cout<<"\n The second strand of the DNA 2:\n ";
        
        for(i=0;i<c2;i++)
            cout<<B12[i]<<"";
    }
    if(t1!=1 || t2!=1)
    {
        cout<<"\n The inputed DNA were incorrect. Kindly re-input.";
        get1(); 
    }
    compare(A11,c1,B11,c2);
}


// check////////
int check(char a11[], char a12[], int c)
{ 
    int i, a=0, b=0,n=0;
    for(i=0;i<c;i++)
    { 
        if(a11[i]=='A')
        {
            if(a12[i]=='T')
                { a++; }
            else
            { b++; 
            break;
            }
        }
        else if(a11[i]=='T')
        {
            if(a12[i]=='A')
                {a++;}
            else
            { b++;
            break;
            }
        }
        else if(a11[i]=='G')
        {
            if(a12[i]=='C')
            {a++;} 
            else
            {
                b++;
                break; }
            
        }
        else if(a11[i]=='C')
        {
            if(a12[i]=='G')
            { a++; }
            else
            { b++;
                break;}
            
        }
        else
        {
            n++;
        }
        
    } 
    if(b==0 &&n==0)
    {
        cout<<"\n The Inputed DNA is correct";
        return 1; }
    else
    {
        cout<<"\n The Inputed DNA is incorrect";
        return 0;
    }
}
// get///////
void get()
{
    int i, n,c1=0, c, length;
    char a1[80], a2[80], t[35];
    cout<<"\nEnter the number of nodes in the DNA: ";
    cin>>n;
    c1=n*10;
    cout<<"\nEnter the first strand of the DNA: \n";
    for(i=0;i<c1;i++)
    cin>>a1[i];

    cout<<"\nEnter the second strand of the DNA: \n";
    for(i=0;i<c1;i++)
    cin>>a2[i];

    c=check(a1,a2,c1);
    if(c==1)
    {
        cout<<"\nThe first strand of the DNA : \n ";
        for(i=0;i<c1;i++)
        {
            cout<<a1[i]<<" ";
        }
        cout<<"\nThe second strand of the DNA :\n ";
        for(i=0;i<c1;i++)
        {
            cout<<a2[i]<<" ";
        }
    }   
    if(c!=1)
    {
        cout<<"\nThe inputed DNA were incorrect. Kindly re-input.";
        get();
    }
    else
    {
        cout<<"\nEnter the length of the characteristics to the compared with the DNA sample: ";
        cin>>length;
        cout<<"\n Enter the characteristics to the compared with the DNA sample \n";
        for(i=0;i<length;i++)
        {
            cin>>t[i];
        }
    kmpsearch(t,a1,length,c1);
    }
}

// kmpsearch//////////
void kmpsearch(char p[], char t[], int m, int n)
{
    int c=0;
    int l[m];
    cout<<"\n\n RESULTS OF THE CHARACTERISTICS COMPARISON OF THE DNA SAMPLE";
    lps(p, m, l);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (p[j] == t[i])
        { 
            j++;
            i++;
        }
        if(j==m)
        {
            c++;
            j = l[j-1];
        }
        else if (i < n && p[j] != t[i])
        { 
            if (j != 0)
                j = l[j-1];
            else
                i =i+1;
        }
        
    }
    if(c==0)
        cout<<"\n\n THE GIVEN CHARACTERISTIC COULD NOT BE FOUND"<<endl;
    else
    {
        double per=(c*m*100)/n;
        cout<<"\n THE DNA HAD "<<per<<"% CHARACTERISTICS"<<endl;
    }
}

//lps////////
void lps(char p[], int m, int l[])
{ 
    int length = 0;
    l[0] = 0;
    int i = 1;
    while (i < m)
    {
        if (p[i] == p[length])
        { 
            length++;
            l[i] = length;
            i++;
        }
        else
        { 
            if (length!=0)
                length = l[length-1];
            else
            {
                l[i] = 0;
                i++;
            }
        }
    }
}
// compare///////////
void compare(char C11[], int a1, char D11[], int a2)
{
    int i, a=0,b=0;
    float n;
    cout<<"\n RESULTS OF DNA SAMPLE COMPARISON :";
    if(a1!=a2)
    {
        cout<<"\n The two DNA's cannot be compared as the strand lengths vary.";
    }
    else
    {
        for(i=0;i<a1;i++)
        {
            if(C11[i]==D11[i])
            {a++;}
            else
            {b++;}
        }
        // cout<<a<<b;
        float x=a,y=b;
        n=(x/((x+y))*100);
        cout<<"\nFrom the comparison of the two DNA samples, it is identified that the percentage of similarity between the two DNA's is :";
        cout<<n;
    }
}
int main()
{
page1();
return 0;
}