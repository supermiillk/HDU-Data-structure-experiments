

LNode MergeSortedLists(CycleLinkList L1, CycleLinkList L2) {
    LNode mergedList;
    InitList(&mergedList);
    LNode *current1 = L1->next;
    LNode *current2 = L2->next;

    while (current1 != L1 && current2 != L2) {
        if (current1->data < current2->data) {
            InsertElement(&mergedList, current1->data);
            current1 = current1->next;
        } else {
            InsertElement(&mergedList, current2->data);
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        InsertElement(&mergedList, current1->data);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        InsertElement(&mergedList, current2->data);
        current2 = current2->next;
    }

    return mergedList;
}
