// Nguyen Thai Hieu - Project1 - 2024.1
// Week 3 - Linked List Manipulation
// LINKED_LIST_MANIPULATION	Accept		80	C	5 / 5	

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node *makeNode(int x) { //Hàm makeNode
    Node *tmp = (Node *)malloc(sizeof(Node));
    if (tmp == NULL) {
        printf("ERROR");
        exit(1);
    }
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

int checkInNode(Node *head, int x) {//Hàm kiểm tra xem x có trong danh sách chưa
    int res = 0;
    Node *p = head;
    while (p != NULL) {
        if (p->data == x) {
            res = 1;
        }
        p = p->next;
    }
    return res;
}

Node *addLastNoCheck(Node *head, int x) { //Thêm vào cuối bất kỳ ptu nào không cần trùng nhaua
    Node *p;
    Node *tmp = makeNode(x);
    if (head == NULL) {
        head = tmp;
    }
    else {
        p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
    return head;
}

Node *addLast(Node *head, int x) {
    if (checkInNode(head, x) == 1) {
        return head;
    }
    else {
        Node *p;
        Node *tmp = makeNode(x);
        if (head == NULL) {
            head = tmp;
        }
        else {
            p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = tmp;
        }
        return head;
    }
}

Node *addFirst(Node *head, int x) {
    if (checkInNode(head, x) == 1) {
        return head;
    }
    else {
        Node *tmp = makeNode(x);
        if (head == NULL) {
            head = tmp;
        }
        else {
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
}

Node *addAfter(Node *head, int u, int v) {
    if (checkInNode(head, u) == 1 || checkInNode(head, v) == 0) {
        return head;
    }
    else {
        Node *tmp = (Node *)malloc(sizeof(Node));
        tmp->data = u;
        tmp->next = NULL;
        Node *p = head;
        while (p != NULL) {
            if (p->data == v) {
                tmp->next = p->next;
                p->next = tmp;
                break;
            }
            p = p->next;
        }
        return head;
    }
}

Node *addBefore(Node *head, int u, int v) {
    if (checkInNode(head, u) == 1 || checkInNode(head, v) == 0) {
        return head;
    }
    else {
        Node *tmp = (Node *)malloc(sizeof(Node));
        tmp->data = u;
        tmp->next = NULL;
        Node *p = head;
        if (p->data == v) {
            tmp->next = p;
            return tmp;
        }
        while (p->next != NULL) {
            if (p->next->data == v) {
                tmp->next = p->next;
                p->next = tmp;
                break;
            }
            p = p->next;
        }
        return head;
    }
}

Node *removeNode(Node *head, int x) {
    Node *p = head;
    Node *old = NULL;

    if (p != NULL && p->data == x) {
        head = p->next;
        return head;
    }
    while (p != NULL && p->data != x) {
        old = p;
        p = p->next;
    }
    if (p == NULL) {
        return head;
    }
    old->next = p->next;
    free(p);
    return head;
}


Node *reverseNode(Node *head) {
    Node *previous = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}
void show(Node *head) {
    Node *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main() {
    Node *head = NULL;
    int n;
    int a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        head = addLastNoCheck(head, a);
    }

    char input[100];
    char str1[20];
    char str2[20];
    char str3[20];
    int int1;
    int int2;

    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "#") == 0) {
            break;
        }

        char *token = strtok(input, " ");
        if (token != NULL) {
            strcpy(str1, token);
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(str2, token);
                token = strtok(NULL, " ");
                if (token != NULL) {
                    strcpy(str3, token);
                }
            }
        }
        int1 = atoi(str2);
        int2 = atoi(str3);

        if (strcmp(str1, "addlast") == 0) {
            head = addLast(head, int1);
        }
        if (strcmp(str1, "addfirst") == 0) {
            head = addFirst(head, int1);
        }
        if (strcmp(str1, "addafter") == 0) {
            head = addAfter(head, int1, int2);
        }
        if (strcmp(str1, "addbefore") == 0) {
            head = addBefore(head, int1, int2);
        }
        if (strcmp(str1, "remove") == 0) {
            head = removeNode(head, int1);
        }
        if (strcmp(str1, "reverse") == 0) {
            head = reverseNode(head);
        }
    }
    show(head);
}
