from __future__ import annotations
from dataclasses import dataclass, field
from typing import Optional
from hashlib import sha256

# LinkedList Definition
@dataclass
class LinkedListNode:
    val: str
    next: Optional[LinkedListNode] = None

@dataclass
class LinkedList:
    head: Optional[LinkedListNode] = None

    def add(self, val: str)-> None:
        node = LinkedListNode(val)

        if self.head is None:
            self.head = node
        else:
            ptr = self.head
            while ptr.next is not None:
                ptr = ptr.next
            ptr.next = node

    def __str__(self):
        res = []
        ptr = self.head
        while ptr is not None:
            res.append(ptr.val)
            ptr = ptr.next
        return " -> ".join(res)

# BST Definition
@dataclass
class BSTNode:
    val: str
    left: Optional[BSTNode] = None
    right: Optional[BSTNode] = None

@dataclass
class BST:
    root: Optional[BSTNode] = None

    @staticmethod
    def insert(root: BSTNode, value: str):
        if value < root.val:
            if root.left:
                BST.insert(root.left, value) 
            else:
                root.left = BSTNode(value)

        else:
            if root.right:
                BST.insert(root.right, value) 
            else:
                root.right = BSTNode(value)


    def add(self, value: str)-> None:
        if self.root is None:
            self.root = BSTNode(value)
        else:
            BST.insert(self.root, value)


# HashTable Definition
@dataclass
class HashTable:
    hashMap: dict[str, str] = field(default_factory=dict)

    def add(self, elem: str) -> None:
        hash = sha256(elem.encode(), usedforsecurity=False)
        self.hashMap[hash] = elem

    def __str__(self):
        return str(self.hashMap)


if __name__ == "__main__":
    keywords = [l.rstrip('\n') for l in open('keywords').readlines()]

    # Array
    array = [x for x in keywords]
    print("Array: ", array)

    # LinkedList
    linked_list = LinkedList()
    for x in keywords:
        linked_list.add(x)
    print("LinkedList: ", linked_list)

    # BST
    bst = BST()
    for x in keywords:
        bst.add(x)
    print("BST: ", bst)


    # Hash Table
    hashTable = HashTable()
    for x in keywords:
        hashTable.add(x)
    print("HashTable : ", hashTable)






