Heaps are a type of [list](01%20Types%20of%20lists.md).

often specifically min-heaps or max-heaps, they are a subcategory of [[binary trees]] that follow extra rules. For this example, we'll use left-justified min-heaps.
**The parent must always be smaller than its children.**
**All heaps must be balanced trees**

Heaps are efficient ways to sort lists, and great for implementing [[priority queues]]

whenever a new element is added, there is a specific method to keep these two properties

```
insert(n):
	find the leftmost available spot in the tree
	insert n into this spot
	BubbleUp(n)
end

BubbleUp(n):
	while n != tree.root:
		if n.getParent()>n:
			swap(n, n.getParent())
end
```

you can only remove the root of a heap, and in order to do that while maintaining the heap, you first swap the root and the last-added element, then bubble down the last element