class TaskModel:
    def __init__(self):
        self.tasks = []

    def add_task(self, title):
        self.tasks.append({'title': title, 'completed': False})

    def remove_task(self, index):
        del self.tasks[index]

    def mark_completed(self, index):
        self.tasks[index]['completed'] = True
