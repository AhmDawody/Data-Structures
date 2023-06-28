typedef int ListEntry;

typedef struct listnode{
    ListEntry entry;
    struct listnode *next, *prev;
}Listnode;

typedef struct list{
    int size, currentpos;
    Listnode *current;
}List;

void CreateList(List *);
int ListEmpty(List *);
int ListFull(List *);
int ListSize(List *);
void InsertList(int ,ListEntry ,List *);
void DeleteList(int, ListEntry *, List *);
void DestroyList(List *);
void TraverseList(List *, void (*)(ListEntry));
void RetrieveList(int , ListEntry*, List*);
void ReplaceList(int , ListEntry , List*);
