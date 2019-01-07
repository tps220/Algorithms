import java.io.*;
import java.util.HashMap; 

class Node {
	public int key;
	public int value;
	public Node next;
	public Node previous;

	public Node(int key, int value) {
		this.key = key;
		this.value = value;
		this.next = null;
		this.previous = null;
	}
}

class DoublyLinkedList {
	public DoublyLinkedList() {
		this.head = this.tail = null;
	}

	public void push(int key, int value) {
		Node candidate = new Node(key, value);
		push(candidate);
	}

	public void push(Node candidate) {
		if (this.head == null && this.tail == null) {
			this.head = this.tail = candidate;
			return;
		}
		candidate.previous = null;
		candidate.next = this.head;
		this.head.previous = candidate;
		this.head = candidate;
	}

	public void moveToFront(Node candidate) {
		if (this.head == null && this.tail == null) {
			this.head = this.tail = candidate;
			return;
		}
		else if (candidate == this.head) {
			return;
		}
		else if (candidate == this.tail) {
			this.tail = this.tail.previous;
			this.tail.next = null;
		}
		else {
			candidate.next.previous = candidate.previous;
			candidate.previous.next = candidate.next;
		}
		push(candidate);
	}

	public void pop() {
		if (this.head == null && this.tail == null) {
			return;
		}
		else if (this.head == this.tail) {
			this.head = null;
			this.tail = null;
			return;
		}
		this.tail = this.tail.previous;
		this.tail.next = null;
	}

	public int peek() {
		return this.tail.key;
	}

	private Node head, tail;
}

class LRUCache {
	public LRUCache(int capacity) {
		this.capacity = capacity;
		ll = new DoublyLinkedList();
		map = new HashMap<Integer, Node>();
	}

	public int get(int key) {
		if (this.map.containsKey(key)) {
			Node candidate = this.map.get(key);
			this.ll.moveToFront(candidate);
			return candidate.value;
		}
		return -1;
	}

	public void put(int key, int value) {
		if (this.map.containsKey(key)) {
			Node candidate = this.map.get(key);
			candidate.value = value;
			ll.moveToFront(candidate);
			return;
		}
		else if (map.size() == capacity) {
			int evictionKey = this.ll.peek();
			this.map.remove(evictionKey);
			this.ll.pop();
		}
		Node candidate = new Node(key, value);
		ll.push(candidate);
		map.put(key, candidate);
	}
	
	private int capacity;
	private DoublyLinkedList ll;
	private HashMap<Integer, Node> map;
}