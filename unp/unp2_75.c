#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cl_st_1 {
	int no;
	char *name;
}CL_ST_1;

CL_ST_1 * CL_ST_1_INIT(void)
{	CL_ST_1 *tmp;
	tmp = (CL_ST_1 *)malloc(sizeof(CL_ST_1));
	bzero(tmp, sizeof(CL_ST_1));
	return tmp;
}


int main(void)
{
	CL_ST_1 *student1;
	student1 = CL_ST_1_INIT();
	/*CL_ST_1 *student1;
	student1 = (CL_ST_1 *)malloc(sizeof(CL_ST_1));
	bzero(student1, sizeof(CL_ST_1));
	*/
	printf("\n*student1 \t size* \t size ");
	printf("\n%p \t %d \t %d ", student1, sizeof(CL_ST_1*),  sizeof(CL_ST_1));
	printf("\nno:%20d", student1->no);
	printf("\nname:%20s", student1->name);
	char nname[] = "LiuCheng";
	student1->no = 123;
	student1->name = nname;
	printf("\n         *nname:%22s", nname);
	printf("\n*student1->name:%22s", student1->name);
	printf("\n     nname@%22p", nname);
	printf("\nstudent1->@%22p", student1->name);


	printf("\n  student1->no:%20d", student1->no);
	printf("\nstudent1->name:%20s", student1->name);
	free( student1);
	printf("\n");
	exit(1);
}
	
