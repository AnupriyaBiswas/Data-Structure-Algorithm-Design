import java.util.LinkedList;
import java.util.Queue;

class SharedBuffer {
    private Queue<Integer> buffer = new LinkedList<>();
    private int capacity;

    public SharedBuffer(int capacity) {
        this.capacity = capacity;
    }

    // Producer method to add items to the buffer
    public synchronized void produce(int value) throws InterruptedException {
        while (buffer.size() == capacity) {
            System.out.println("Buffer is full, producer waiting...");
            wait();
        }
        buffer.add(value);
        System.out.println("Produced: " + value);
        notify();  // Notify consumer that a new item is available
    }

    // Consumer method to remove items from the buffer
    public synchronized int consume() throws InterruptedException {
        while (buffer.isEmpty()) {
            System.out.println("Buffer is empty, consumer waiting...");
            wait();
        }
        int value = buffer.poll();
        System.out.println("Consumed: " + value);
        notify();  // Notify producer that an item has been consumed
        return value;
    }
}

// Producer thread class
class Producer extends Thread {
    private SharedBuffer buffer;

    public Producer(SharedBuffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 10; i++) {
            try {
                buffer.produce(i);
                Thread.sleep(500); // Simulating production delay
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

// Consumer thread class
class Consumer extends Thread {
    private SharedBuffer buffer;

    public Consumer(SharedBuffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 10; i++) {
            try {
                buffer.consume();
                Thread.sleep(1000); // Simulating consumption delay
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

// Main class to run the producer-consumer example
public class Prog9002i
{
    public static void main(String[] args) {
        SharedBuffer buffer = new SharedBuffer(5);  // Buffer with capacity 5
        Producer producer = new Producer(buffer);
        Consumer consumer = new Consumer(buffer);

        producer.start();
        consumer.start();
    }
}
