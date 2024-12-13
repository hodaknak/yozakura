// Sample Java Code: Simple CLI To-Do App
import java.util.ArrayList;
import java.util.Scanner;

class Task {
    String text;
    boolean completed;

    Task(String text) {
        this.text = text;
        this.completed = false;
    }

    @Override
    public String toString() {
        return (completed ? "[X] " : "[ ] ") + text;
    }
}

public class ToDoApp {

    private static void displayTasks(ArrayList<Task> tasks) {
        System.out.println("\nTo-Do List:");
        if (tasks.isEmpty()) {
            System.out.println("  No tasks yet!");
        } else {
            for (int i = 0; i < tasks.size(); i++) {
                System.out.println("  " + (i + 1) + ". " + tasks.get(i));
            }
        }
    }

    private static void addTask(ArrayList<Task> tasks, Scanner scanner) {
        System.out.print("Enter a task: ");
        String taskText = scanner.nextLine().trim();
        if (!taskText.isEmpty()) {
            tasks.add(new Task(taskText));
            System.out.println("Task added!");
        } else {
            System.out.println("Task cannot be empty.");
        }
    }

    private static void deleteTask(ArrayList<Task> tasks, Scanner scanner) {
        System.out.print("Enter task number to delete: ");
        int taskNum = scanner.nextInt();
        scanner.nextLine(); // consume newline
        if (taskNum > 0 && taskNum <= tasks.size()) {
            tasks.remove(taskNum - 1);
            System.out.println("Task deleted!");
        } else {
            System.out.println("Invalid task number.");
        }
    }

    private static void toggleTaskCompletion(ArrayList<Task> tasks, Scanner scanner) {
        System.out.print("Enter task number to toggle completion: ");
        int taskNum = scanner.nextInt();
        scanner.nextLine(); // consume newline
        if (taskNum > 0 && taskNum <= tasks.size()) {
            Task task = tasks.get(taskNum - 1);
            task.completed = !task.completed;
            System.out.println("Task status updated!");
        } else {
            System.out.println("Invalid task number.");
        }
    }

    public static void main(String[] args) {
        ArrayList<Task> tasks = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\nOptions:");
            System.out.println("  1. View tasks");
            System.out.println("  2. Add task");
            System.out.println("  3. Delete task");
            System.out.println("  4. Toggle task completion");
            System.out.println("  5. Exit");

            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // consume newline

            switch (choice) {
                case 1 -> displayTasks(tasks);
                case 2 -> addTask(tasks, scanner);
                case 3 -> deleteTask(tasks, scanner);
                case 4 -> toggleTaskCompletion(tasks, scanner);
                case 5 -> {
                    System.out.println("Goodbye!");
                    scanner.close();
                    return;
                }
                default -> System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
