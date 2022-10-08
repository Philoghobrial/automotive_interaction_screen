/*
 ============================================================================
 Name        : project_1.c
 Author      : philopater ghobrial
 Description : vehicle control system
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void disp(void);
struct status{
	char eng_stat[4];
	char AC_stat[4];
	int veh_speed;
	int room_temp;
	char eng_cont_temp[4];
	int eng_temp;
}status1;
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	strcpy(status1.AC_stat,"OFF");
	strcpy(status1.eng_stat,"OFF");
	strcpy(status1.eng_cont_temp,"OFF");
	printf("     hello to philo automotive program\n");
	printf("how can i help you?? \n\n\n");
	char y;
	while(1){
		printf("a.turn on the vehicle engine \n");
		printf("b.turn off the vehicle engine \n");
		printf("c.quit the system\n \n");
		printf("enter the alphabet of the choosen program \n");
		char input;
		scanf(" %c",&input);
		switch(input)
		{
		case'a':
			printf("vehicle has been turned on successfully \n\n");
			strcpy(status1.eng_stat,"ON");
			printf("**********************************************\n");
			while(y !='a'){
				printf("           sensors set menu\n\n");
				printf("a.turn off the engine \n");
				printf("b.set the traffic light colour \n");
				printf("c.set the room temperature \n");
				printf("d.set the engine temperature\n");
				printf("enter the alphabet of the choosen program \n");
				scanf(" %c",&y);
				switch(y)
			{
			case'b':
				printf("enter traffic light colour\n");
				char colour;
				printf("enter colour of traffic light\n");
				scanf("  %c",&colour);
				switch (colour)
				{
				case'g':
					strcpy(status1.eng_stat,"ON");
					status1.veh_speed=100;
					disp();
					break;
				case'o':
					strcpy(status1.AC_stat,"ON");
					status1.room_temp=status1.room_temp*(5/4)+1;
					strcpy(status1.eng_stat,"ON");
					status1.eng_temp=status1.eng_temp*(5/4)+1;
					status1.veh_speed=30;
					disp();
					break;
				case'r':
					strcpy(status1.eng_stat,"ON");
					status1.veh_speed=0;
					disp();
					break;
				}
				break;
				case'c':
					printf("enter value of room temp \n");
					int roomtemp;
					scanf("%d",&roomtemp);
					if(roomtemp<10 || roomtemp>30)
					{
						if(roomtemp<10)
						{
							strcpy(status1.AC_stat,"ON");
							status1.room_temp=20;
						}
						else
						{
							strcpy(status1.AC_stat,"ON");
							status1.room_temp=20;
						}
					}
					else{
					strcpy(status1.AC_stat,"OFF");
					}
					disp();
					break;
				case'd':
					printf("enter value of engine temperature \n");
					int enginetemp;
					scanf("%d",&enginetemp);
					if((enginetemp<100) || (enginetemp>150))
					{
						if(enginetemp<100)
						{
							strcpy(status1.eng_cont_temp,"ON");
							status1.eng_temp=125;
						}
						else
						{
							strcpy(status1.eng_cont_temp,"ON");
							status1.eng_temp=125;
						}
					}
					else
					{
						strcpy(status1.eng_cont_temp,"OFF");
					}
					disp();
					break;
			}

			}
		while (y == 'a'){
			printf("engine turned off successfully\n\n");
			printf("**********************************************\n");
			strcpy(status1.eng_stat,"OFF");
			y=0;
			break;
		}
break;
		case'b':
			printf("vehicle has been turned off successfully \n");
			printf("**********************************************\n");
			break;

		case'c':
			printf("system quited successfully\n");
			return 0;
			break;
		}

	}
}
void disp(void){
	printf("engine status:%s\n",status1.eng_stat);
	printf("AC status:%s\n",status1.AC_stat);
	printf("speed of vehicle is %d km/h \n",status1.veh_speed);
	printf("room temperature = %d C \n",status1.room_temp);
	printf("engine controller temperature = %s C  \n",status1.eng_cont_temp);
	printf("engine temperature = %d C \n\n ",status1.eng_temp);
	printf("**********************************************\n");
}
