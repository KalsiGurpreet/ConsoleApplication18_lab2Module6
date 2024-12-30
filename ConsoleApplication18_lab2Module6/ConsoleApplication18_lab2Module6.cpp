#include<stdio.h>
#include<stdlib.h>

struct HOUSE
{
	short houseNumber;
	struct HOUSE* pprevious;
	struct HOUSE* pnext;
};

int main()
{
	struct HOUSE house[4];
	struct HOUSE* pfirstHouse, *plastHouse, *pcurrent;

	pfirstHouse = house;
	plastHouse = house + 3;


	house->houseNumber = 1;
	(house + 1)->houseNumber = 3;
	house[2].houseNumber = 5;   // ~ house + 2
	house[3].houseNumber = 7;   // ~ to house + 3

	// pfirstHouse = (struct HOUSE*)malloc(sizeof(struct HOUSE));

	house[0].pnext = house + 1;
	house[1].pnext = house + 2;
	house[2].pnext = house + 3;
	house[3].pnext = NULL;

	printf("%p\n", house);
	printf("%p\n", house[0].pnext);
	printf("%p\n", house[1].pnext);
	printf("%p\n", house[2].pnext);
	printf("%p\n", house[3].pnext);

	house[0].pprevious = NULL;
	house[1].pprevious = house;
	house[2].pprevious = house + 1;
	house[3].pprevious = house + 2;    //&house[2]

	// free(pfirstHouse);

	pcurrent = pfirstHouse;

	while (pcurrent != NULL)
	{
		printf("House number is %d\n", pcurrent->houseNumber);
		pcurrent = pcurrent->pnext;
	}

	pcurrent = plastHouse;

	while (pcurrent != NULL)
	{
		printf("House number is %d\n", pcurrent->houseNumber);  // pcurrent = plasthouse and plasthouse = house + 3
		pcurrent = pcurrent->pprevious;
	}

	return 0;
}