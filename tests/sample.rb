# Sample Ruby Code: Simple CLI To-Do App

def display_tasks(tasks)
    puts "\nTo-Do List:"
    if tasks.empty?
      puts "  No tasks yet!"
    else
      tasks.each_with_index do |task, index|
        status = task[:completed] ? "[X]" : "[ ]"
        puts "  #{index + 1}. #{status} #{task[:text]}"
      end
    end
  end
  
  def add_task(tasks)
    print "Enter a task: "
    task_text = gets.chomp.strip
    if task_text.empty?
      puts "Task cannot be empty."
    else
      tasks << { text: task_text, completed: false }
      puts "Task added!"
    end
  end
  
  def delete_task(tasks)
    print "Enter task number to delete: "
    task_num = gets.chomp.to_i
    if task_num.between?(1, tasks.size)
      tasks.delete_at(task_num - 1)
      puts "Task deleted!"
    else
      puts "Invalid task number."
    end
  end
  
  def toggle_task_completion(tasks)
    print "Enter task number to toggle completion: "
    task_num = gets.chomp.to_i
    if task_num.between?(1, tasks.size)
      tasks[task_num - 1][:completed] = !tasks[task_num - 1][:completed]
      puts "Task status updated!"
    else
      puts "Invalid task number."
    end
  end
  
  def main
    tasks = []
    loop do
      puts "\nOptions:"
      puts "  1. View tasks"
      puts "  2. Add task"
      puts "  3. Delete task"
      puts "  4. Toggle task completion"
      puts "  5. Exit"
  
      print "Choose an option: "
      choice = gets.chomp
  
      case choice
      when "1"
        display_tasks(tasks)
      when "2"
        add_task(tasks)
      when "3"
        delete_task(tasks)
      when "4"
        toggle_task_completion(tasks)
      when "5"
        puts "Goodbye!"
        break
      else
        puts "Invalid choice. Please try again."
      end
    end
  end
  
  main
  