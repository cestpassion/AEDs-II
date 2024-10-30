class Stack {
    private int maxSize;
    private int top;
    private int[] stackArray;

    // Construtor da pilha
    public Stack(int size) {
        this.maxSize = size;
        this.stackArray = new int[maxSize];
        this.top = -1;
    }

    // Verifica se a pilha está vazia
    public boolean isEmpty() {
        return (top == -1);
    }

    // Verifica se a pilha está cheia
    public boolean isFull() {
        return (top == maxSize - 1);
    }

    // Insere um elemento na pilha
    public void push(int value) {
        if (isFull()) {
            System.out.println("Stack overflow");
        } else {
            stackArray[++top] = value;
        }
    }

    // Remove um elemento da pilha
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack underflow");
            return Integer.MIN_VALUE;
        } else {
            return stackArray[top--];
        }
    }

    // Retorna o elemento no topo da pilha sem removê-lo
    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return Integer.MIN_VALUE;
        } else {
            return stackArray[top];
        }
    }

    // Testa a pilha
    public static void main(String[] args) {
        Stack stack = new Stack(5);

        stack.push(10);
        stack.push(20);
        System.out.println("Top element is " + stack.peek());

        System.out.println("Removed " + stack.pop() + " from stack");
        System.out.println("Top element is now " + stack.peek());
    }
}
