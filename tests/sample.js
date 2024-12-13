// Sample JavaScript Code: Simple To-Do App

// HTML setup with JavaScript
const app = document.getElementById('app');
app.innerHTML = `
  <h1>To-Do List</h1>
  <input type="text" id="todo-input" placeholder="Enter a task">
  <button id="add-task">Add Task</button>
  <ul id="todo-list"></ul>
`;

// State to hold tasks
let tasks = [];

// Function to render tasks
function renderTasks() {
    const list = document.getElementById('todo-list');
    list.innerHTML = '';
    tasks.forEach((task, index) => {
        const li = document.createElement('li');
        li.className = 'task';
        li.innerHTML = `
      <span>${task.text}</span>
      <button class="delete-task" data-index="${index}">Delete</button>
      <button class="toggle-complete" data-index="${index}">
        ${task.completed ? 'Mark Incomplete' : 'Mark Complete'}
      </button>
    `;
        if (task.completed) li.querySelector('span').classList.add('completed');
        list.appendChild(li);
    });
}

// Event handler for adding a task
document.getElementById('add-task').addEventListener('click', () => {
    const input = document.getElementById('todo-input');
    const text = input.value.trim();
    if (text) {
        tasks.push({ text, completed: false });
        input.value = '';
        renderTasks();
    } else {
        alert('Please enter a task.');
    }
});

// Event delegation for task actions
document.getElementById('todo-list').addEventListener('click', (e) => {
    const index = e.target.dataset.index;
    if (e.target.classList.contains('delete-task')) {
        tasks.splice(index, 1);
        renderTasks();
    } else if (e.target.classList.contains('toggle-complete')) {
        tasks[index].completed = !tasks[index].completed;
        renderTasks();
    }
});

// Initial render
renderTasks();

// Styling
const style = document.createElement('style');
style.innerHTML = `
  body {
    font-family: Arial, sans-serif;
    margin: 20px;
  }
  h1 {
    color: #333;
  }
  input {
    padding: 10px;
    width: 200px;
    margin-right: 10px;
  }
  button {
    padding: 10px;
    background-color: #007BFF;
    color: white;
    border: none;
    border-radius: 4px;
    cursor: pointer;
  }
  button:hover {
    background-color: #0056b3;
  }
  ul {
    list-style-type: none;
    padding: 0;
  }
  .task {
    display: flex;
    align-items: center;
    justify-content: space-between;
    padding: 10px;
    background-color: #f9f9f9;
    margin: 5px 0;
    border: 1px solid #ddd;
    border-radius: 4px;
  }
  .task .completed {
    text-decoration: line-through;
    color: gray;
  }
`;
document.head.appendChild(style);
