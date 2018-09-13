#define NMAX 100
struct stack
{
	float elem[NMAX];
	int top;
};

void init(struct stack * stk, float f)
{
	stk->top = 0;	
};

void push(struct stack * stk, float f)
{
	if(stk->top < NMAX) {
		stk->elem[stk -> top] = f;
		stk -> top++;
	} else printf("Стек полный, кол-во эл-тов: %d\n", stk->top);
};

float pop(struct stack *stk)
{
	float elem;
	if((stk->top) > 0){
		stk->top--;
		elem = stk->elem[stk->top];
		return(elem);
	}	else {
		printf("Stek pust\n");
		return 0;
	}
};

float pop(struct stack *stk) {
  float elem;
  if((stk->top) > 0) {
    stk->top—;
    elem = stk->elem[stk->top];
    return(elem);
  } else {
    printf(«Стек пуст!\n»);
    return(0);
  }
}


float stkTop(struct stack *stk) {
  if((stk->top) > 0) {
    return( stk->elem[stk->top-1]);
  } else {
    printf(«Стек пуст!\n»);
    return(0);
  }
}

void stkPrint(struct stack *stk) {
  int i;
  i=stk->top;
  if(isempty(stk)==1) return;
  do {
    i—;
    printf(«%f\n», stk->elem[i]);
  }while(i>0);
}

int gettop(struct stack *stk) {
 return(stk->top);}


int main(int argc, char const *argv[])
{
	//stack
	struct stack *stk;
  int i,n;
  float elem;
  stk = (struct stack*)malloc(sizeof(struct stack));
  init(stk);
  printf(«Введите количество элементов в стеке: «);
  scanf(«%d», &n);
  for(i=0;i<n;i++) {
    printf(«Введите элемент %d:», i);
    scanf(«%f», &elem);
    push(stk,elem);
  }
  printf(«В стеке %d элементов\n», gettop(stk));
  printf(«\n»);
  stkPrint(stk);
  printf(«Верхний элемент %f\n»,stkTop(stk));
  do {
    printf(«Извлекаем элемент %f, «, pop(stk));
    printf(«в стеке осталось %d элементов\n», gettop(stk));
  } while(isempty(stk)==0);
  getch(); getch();
	return 0;
}