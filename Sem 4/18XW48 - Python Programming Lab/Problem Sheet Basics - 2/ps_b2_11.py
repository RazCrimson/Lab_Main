def execute_command(variables,expression):
    try:
        return eval(expression,variables)
    except NameError:
        print('Value not defined')


print('Enter the command : ')
variables = {}
try:
    while True:
        command = input('>>> ')
        if 'print' in command.lower():
            expression = command.split('print ')
            result = execute_command(variables,expression[1])
            print(result)
        elif 'let' in command.lower():
            equal_index = command.find('=')
            let_index = command.find('let')
            value = execute_command(variables,command[equal_index+1 :])
            variables[command[let_index+4:equal_index-1]] = value
        elif command == 'clear':
            variables.clear()
        else:
            break
except KeyboardInterrupt:
    print(' Keyboard Interrupt!')