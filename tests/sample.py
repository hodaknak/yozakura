# Sample Python Code: Simple CLI To-Do App

def display_tasks(tasks):
    print("\nTo-Do List:")
    if not tasks:
        print("  No tasks yet!")
    for i, task in enumerate(tasks, 1):
        status = "[X]" if task['completed'] else "[ ]"
        print(f"  {i}. {status} {task['text']}")

def add_task(tasks):
    task_text = input("Enter a task: ").strip()
    if task_text:
        tasks.append({"text": task_text, "completed": False})
        print("Task added!")
    else:
        print("Task cannot be empty.")

def delete_task(tasks):
    try:
        task_num = int(input("Enter task number to delete: "))
        if 1 <= task_num <= len(tasks):
            tasks.pop(task_num - 1)
            print("Task deleted!")
        else:
            print("Invalid task number.")
    except ValueError:
        print("Please enter a valid number.")

def toggle_task_completion(tasks):
    try:
        task_num = int(input("Enter task number to toggle completion: "))
        if 1 <= task_num <= len(tasks):
            tasks[task_num - 1]['completed'] = not tasks[task_num - 1]['completed']
            print("Task status updated!")
        else:
            print("Invalid task number.")
    except ValueError:
        print("Please enter a valid number.")

def main():
    tasks = []
    while True:
        print("\nOptions:")
        print("  1. View tasks")
        print("  2. Add task")
        print("  3. Delete task")
        print("  4. Toggle task completion")
        print("  5. Exit")
        
        choice = input("Choose an option: ")
        if choice == "1":
            display_tasks(tasks)
        elif choice == "2":
            add_task(tasks)
        elif choice == "3":
            delete_task(tasks)
        elif choice == "4":
            toggle_task_completion(tasks)
        elif choice == "5":
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
