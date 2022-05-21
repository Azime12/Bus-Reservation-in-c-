        #include<iostream>

        using namespace std;

      // n is the number of the bus
        int  n=0;
        int  busSeatCouter[8];
        //declaration of the structure
        struct Bus{
        string driverName,to,from;
        float  arivalTime,departure;
        int busNo;
        int seat[32];
        string cName[32];
        };

        //global declaration of the bus information

        Bus bus[8];

        //initialize the bus seat to 0

      void initailizeCounter()
      {

          //initialize all the bus seat to 0
                 for(int i=0;i<8;i++)
              {

            for(int j=0;j<32;j++)
               {
                bus[i].seat[j]=0;
               }
              }
          for(int i=0;i<8;i++)
          {
                 busSeatCouter[i]=0;

          }
      }



        void add()
        {
            int busNo;
          d:  cout<<"\n\t\t Enter bus number:";
           cin>>busNo;

            for(int i=0;i<=n;i++)
            {
                if(bus[i].busNo!=busNo)
                {
                 bus[n].busNo=busNo;
            cout<<"\n\t\t Enter diver name:";
            cin>>bus[n].driverName;
             cout<<"\n\t\t Enter bus From:";
            cin>>bus[n].from;
            cout<<"\n\t\t Enter bus where to:";
            cin>>bus[n].to;

            cout<<"\n\t\t Enter departure time:";
            cin>>bus[n].departure;
            cout<<"\n\t\t Enter arrive time:";
            cin>>bus[n].arivalTime;

            n++;
            break;

                }
                else{
                    cout<<"\n\t\t bus is already exit please try another bus";
                    goto d;
                }
            }


            }
//seat reservation function
            void reservestion()
            {
                int busNo;
                int seatNo;
                int seatCounter=1;

                int busExit;
                bool busCheck=false;
                bool seatcheck=false;
             b:  g: cout<<"\n\n\tEnter the bus number:";
                cin>>busNo;

                //for loop if the bus is exit
                for(int i=0;i<8;i++){
                    if(bus[i].busNo==busNo)
                        {
                            busCheck=true;
                            busExit=i;
                            break;
                        }
                    }

                 //check the the seat no is free or not
                    if(busCheck)
                    {
                     c:   f: cout<<"\n\t Enter the seat number";
                        cin>>seatNo;


                        if(seatNo<=32&& seatNo>0)
                        {
                            for(int j=0;j<32;j++)
                            {
                                if(bus[busExit].seat[seatNo-1]==seatNo)
                                {
                                    break;

                                }
                                else if(bus[busExit].seat[seatNo-1]!=seatNo&&bus[busExit].seat[seatNo-1]==0){
                                        bus[busExit].seat[seatNo-1]=seatNo;
                                    cout<<"\n\t Enter Name: ";
                                    cin>>bus[busExit].cName[seatNo-1];
                                    seatcheck=true;
                                    busSeatCouter[busExit]++;
                                    break;

                                }
                                }


                            if(seatcheck==false)
                        {
                            cout<<"\n\t\t seat is already reserved please try again";

                            goto f;

                        }
                        else if(seatcheck==false&&busSeatCouter[busExit]<32){
                            cout<<"\n\t bus is full no seat free please try another bus";
                            goto b;
                        }


                        }
                        else{
                            cout<<"\n\t seat number is 1-32";
                            goto c;
                        }
                    }
                    else{
                    cout<<"\n\n\t\t no bus is found please enter correct bus number";
                    goto g;

                    }



         }//end function



          void display()
                {
                    int busNo;
                   bool busCheck=true;
                   int busExit;
                    cout<<"\n\n\t\t available bus  ";
                    for(int i=0;i<n;i++)
                    {
                        cout<<"\n\t\t\t"<<bus[i].busNo;

                    }

                   e:  cout<<"\n\t\t Enter the bus number that you want:";
                     cin>>busNo;

                     //check bus is exit or not
                     for(int i=0;i<8;i++){
                    if(bus[i].busNo==busNo)
                        {
                            busCheck=true;
                            busExit=i;
                            break;
                        }
                    }

                    //
                    if(busCheck)
                    {
                     cout<<"\n\t*******************************************************************************************";

                     cout<<"\n\t Driver:\t"<<bus[busExit].driverName<<"\tArrival time:\t"<<bus[busExit].arivalTime<<"\t departure time:\t"<<bus[busExit].departure;
                     cout<<"\n\t From:  \t"<<bus[busExit].from<<"\t    To: \t"<<bus[busExit].to;

                     cout<<"\n\t*******************************************************************************************";
                         for(int i=0;i<32;i=i+4)
                      {
                          string name;
                          cout<<endl;
                          for(int j=1;j<5;j++)
                          {
                              if(bus[busExit].seat[i+j-1]==0)
                              {
                                  name="empty";
                              }else{
                                  name=bus[busExit].cName[i+j-1];
                              }

                              cout<<"\t"<<i+j<<"."<<"\t"<<name;
                          }
                          cout<<endl;

                      }
                      cout<<"\n\t\t\t There are "<<32-busSeatCouter[busExit]<<" seat empty is the bus number "<<bus[busExit].busNo;
                      for(int i=0;i<32;i++)
                      {
                          if(bus[busExit].seat[i]!=0)
                          {
                              cout<<"\n\t\t\t The seat number "<<bus[busExit].seat[i]<<" is reserved for "<<bus[busExit].cName[i];
                          }

                      }



                    }
                    else{
                    cout<<"\n\n\t\t no bus is found please enter correct bus number";
                    goto e;

                    }


                    }


            //delete function
                    void deleteCusm()
                    {
                        int busNo;
                         bool busCheck=false;
                        int busExit;
                        int seatNo;
                       bool seatCheck=false;
                        cout<<"\n\t\t Enter the bus number:";
                        cin>>busNo;

                        //find the bus
                         for(int i=0;i<8;i++){
                    if(bus[i].busNo==busNo)
                        {
                            busCheck=true;
                            busExit=i;
                            break;
                        }
                    }

                    //delete start if the bus is exit otherwise not
                    if(busCheck)

                    {
                        cout<<"\n\t\t Enter the seat Number:";
                        cin>>seatNo;
                         for(int i=0;i<32;i++)
                            {
                                if(bus[busExit].seat[i]==seatNo)
                                {

                                  bus[busExit].seat[i]=0;
                                  bus[busExit].cName[i]="";
                                  busSeatCouter[busExit]--;
                                  cout<<"\n\t successfully Deleted!";
                                  seatCheck=true;
                                  break;

                                }
                                }
                                if(seatCheck==false)
                                {
                               cout<<"\n\t seat number was free or not found";
                                }


                         }

                    }


                    void searchCus(){
                    int busNo,seatNO;
                    bool found=false;
                    int busExit;
                    bool busCheck=false;
                    cout<<"\n\t Enter the Bus Number:";
                    cin>>busNo;
                       for(int i=0;i<8;i++){
                    if(bus[i].busNo==busNo)
                        {
                            busCheck=true;
                            busExit=i;
                            break;
                        }
                    }

                    if(busCheck)
                    {
                        cout<<"\n\t Enter seat number:";
                        cin>>seatNO;
                        for(int i=0;i<32;i++)
                        {
                            if(bus[busExit].seat[i]==seatNO)
                            {
                                cout<<"\n\t bus number :"<<bus[busExit].busNo;
                                cout<<"\n\t seat number:"<<bus[busExit].seat[i];
                                cout<<"\n\t Customer name:"<<bus[busExit].cName[i];
                                found=true;
                                break;

                            }


                        }

                        if(found==false)
                        {

                            cout<<"\n\t seat number not found or not reserved";
                        }


                    }else{
                    cout<<"\n\t bus not found ";
                    }
                    }

//update function
         void update(){
                    int busNo,seatNO;
                    bool found=false;
                    int busExit;
                    bool busCheck=false;
                    cout<<"\n\t Enter the Bus Number:";
                    cin>>busNo;
                       for(int i=0;i<8;i++){
                    if(bus[i].busNo==busNo)
                        {
                            busCheck=true;
                            busExit=i;
                            break;
                        }
                    }

                    if(busCheck)
                    {
                        cout<<"\n\t Enter seat number:";
                        cin>>seatNO;
                        for(int i=0;i<32;i++)
                        {
                            if(bus[busExit].seat[i]==seatNO&&(seatNO>0&&seatNO<=32))
                            {
                                      cout<<"\n\t Enter the name:";
                                      cin>>bus[busExit].cName[i];
                                      cout<<"\n\t successfully updated!";
                                found=true;
                                break;

                            }


                        }

                        if(found==false)
                        {

                            cout<<"\n\t seat number wrong or not reserved";
                             cout<<"\n\t please try again";

                        }


                    }else{
                    cout<<"\n\t bus not found ";
                    }
   }



            void menu()
            {
             initailizeCounter();
              //menu start here
                while(true)
                {
                     a: cout<<"\n\n\t\t\t*************************************************";
                cout<<"\n\n\t\t\t\t \t\tWelcome To ";
                cout<<"\n\t\t\t\t\t Anbesa Bus Reservation System ";
                cout<<"\n\n\t\t\t**************************************************";

                cout<<"\n\n\n\n\t\t\t\t  1 to Add new Bus";
                cout<<"\n\t\t\t\t  2 to show ";
                cout<<"\n\t\t\t\t  3 to Reservation";
                cout<<"\n\t\t\t\t  4 to delete custumer";
                cout<<"\n\t\t\t\t  5 to update";
                cout<<"\n\t\t\t\t  6 to search";
                cout<<"\n\t\t\t\t  7 to Exit";
                cout<<"\n\t\t\t\t  Enter a choise";
                char choise;
                cin>>choise;



            switch(choise)

            {
            case '1':
                add();
                system("cls");
                break;
            case '2':
                system("cls");
                display();

                break;
            case '3':
                 reservestion();
                 system("cls");
                break;
            case '4':
                system("cls");
                deleteCusm();
                 break;
            case '5':
                system("cls");
                update();
                break;
            case '6':
                system("cls");
                searchCus();
                break;

            case '7':
                exit(1);
                break;
            default:
                system("cls");
                cout<<"\n\t\t\t wrong choice please try again!!";

                goto a;

                }

                }


            }



            int main()
                {

           menu();

                }
