int binarniSearch(int v[], int n, int x)
{
  int dg = 0;
  int gg = n - 1;
  int s = 0;

  while (dg <= gg)
  {
    s = (dg + gg) / 2;
    if (v[s] == x)
    {
      return s;
    }
    else if (v[s] > x)
    {
      gg = s - 1;
    }
    else if (v[s] < x)
    {
      dg = s + 1;
    }
  }

  if (dg > gg)
  {
    return -1;
  }
}

void selectionSort(int v[], int n)
{
  for (int i = 0; i < (n - 1); i++)
  {
    int min = i;

    for (int j = i + 1; j < n; j++)
    {
      if (v[j] < v[min])
      {
        min = j;
      }
    }

    if (min != i)
    {
      int temp = v[i];
      v[i] = v[min];
      v[min] = temp;
    }
  }
}

void bubbleSort(int v[], int n)
{

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (v[j + 1] < v[j])
      {
        int temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
  }
}

void insertionSort(int v[], int n)
{

  int j;
  for (int i = 1; i < n; i++)
  {
    int temp = v[i];

    j = i - 1;

    while (j >= 0 && v[j] > temp)
    {
      v[j + 1] = v[j];
      j = j - 1;
    }
    v[j + 1] = temp;
  }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int x;
  struct Node *nextNode;
} Node;

Node *createNode(int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));

  if (!newNode)
  {
    return NULL;
  }

  newNode->x = value;
  newNode->nextNode = NULL;
  return newNode;
}

void addToEnd(Node **head, int value)
{
  Node *newNode = createNode(value);

  if (*head == NULL)
  {
    *head = newNode;
    return;
  }

  Node *temp = *head;
  while (temp->nextNode != NULL)
  {
    temp = temp->nextNode;
  }
  temp->nextNode = newNode;
}

void printList(Node *head)
{
  Node *temp = head;
  int brojCvorova = 0;
  while (temp != NULL)
  {
    printf("%d ", temp->x);
    brojCvorova++;
    temp = temp->nextNode;
  }
  printf("\nBroj cvorova je %d\n", brojCvorova);
}

float srednjaVrijednost(Node *head)
{
  Node *temp = head;
  int brojac = 0;
  int zbroj = 0;
  float avg = 0;

  while (temp != NULL)
  {
    zbroj += temp->x;
    brojac++;
    temp = temp->nextNode;
  }
  avg = (float)zbroj / brojac;

  printf("\nSrednja vrijednost je %.3f", avg);
  return avg;
}

void brojPozitivnih(Node *head, float avg)
{

  Node *temp = head;
  int brojac = 0;
  while (temp != NULL)
  {
    if ((temp->x > 0) && (temp->x > avg))
    {
      brojac++;
    }
    temp = temp->nextNode;
  }

  printf("\nBroj pozitivnih elemenata je: %d", brojac);
}

void numberOfNegativeElements(Node *head)
{
  Node *temp = head;
  int brojac = 0;

  while (temp != NULL)
  {
    if (temp->x < 0)
    {
      brojac++;
    }
    temp = temp->nextNode;
  }
  printf("\nBroj negativnih elemenata je: %d", brojac);
}

void freeList(Node **head)
{
  Node *currentNode = *head;
  Node *nextNode;

  while (currentNode != NULL)
  {
    nextNode = currentNode->nextNode;
    free(currentNode);
    currentNode = nextNode;
  }
  *head = NULL;
}

int main(void)
{

  Node *head = NULL;

  int m;
  int n;

  printf("Upisite broj elemenata i elemente\n");
  scanf("%d", &m);

  for (int i = 0; i < m; i++)
  {
    scanf("%d", &n);
    addToEnd(&head, n);
  }

  printList(head);
  float avg = srednjaVrijednost(head);
  numberOfNegativeElements(head);
  brojPozitivnih(head, avg);

  freeList(&head);
  return 0;
}