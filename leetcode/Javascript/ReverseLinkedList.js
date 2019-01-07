function ListNode(val) {
    this.val = val;
    this.next = null;
}

var reverseList = function(head) {
    if (head === null || head.next === null) {
        return head;
    }
    let prv = null;
    let curr = head;
    let runner = head.next;

    while (curr != null) {
        curr.next = prv;
        prv = curr;
        curr = runner;
        if (runner != null) {
            runner = runner.next;
        }
    }

    return prv;
};
