% Qn 1
X = [1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10];
Y = [2, 5, 6, 7, 8, 10, 13, 15, 18, 19]
plot(X, Y, '*-')

% Qn 2
X = [1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10];
Y = [2, 5, 6, 7, 8, 10, 13, 15, 18, 19];
p = plot(X, Y, ':or', ...
    'LineWidth', 2,...
    'MarkerEdgeColor', 'g',...
    'MarkerFaceColor', 'y',...
    'MarkerSize', 12);

% Qn 3
x = -2:0.01:4;
y = (((3.5).^(-0.5 * x))).*cos(6*x);
plot(x, y);

% Qn 4
x = 1:0.01:10;
plot(x, x.^2, x, x.^3, x, log10(x), x, 1./x)

% Qn 5
x = 0:pi/100:2*pi;
plot(x,sin(x), x, cos(x), x, tan(x))

% Qn 6
y = @(x) ((x+5)*2)/(4+3*((x)*2));
fplot(y,[-3 5])
grid on
xlabel('x');
ylabel('y');

% Qn 7
x = linspace(-2,4);

func = 3.*((x).^3)-26.*x+10;
func_first = diff(func);
func_second = diff(func_first);
vec_1 = x(1:end-1);
vec_2 = x(1:end-2);
plot(x, func, vec_1, func_first, vec_2, func_second) 

% Qn 8
x = linspace(-2,4);

func = 3.*((x).^3)-26.*x+10;
func_first = diff(func);
func_second = diff(func_first);
vec_1 = x(1:end-1);
vec_2 = x(1:end-2);
plot(x, func)
hold on
plot(vec_1, func_first)
hold on
plot(vec_2, func_second)

% Qn 9
vec_1 = linspace(-2,4);
func = 3.*((vec_1).^3)-26.*vec_1+10;
func_first = diff(func);
func_second = diff(func_first);
vec_2 = vec_1(1:end-1);
vec_3 = vec_1(1:end-2);
x = [vec_1 vec_2 vec_3]
y = [func func_first func_second]
line(x, y)

% Qn 10
x = 10:0.01:22;
y = 95000./((x).^2);
X = 10:2:22;
Y = [950, 640, 460, 340, 250, 180, 140];
plot(x, y);
hold on;
plot(X,Y,':or');
xlabel('Distance (cm)');
ylabel('Intensity (lux)');
title('Light Intensity as a Function of Distance')
axis([8 24 0 1200])
text(14,640, 'Comparision between theory and exeriment', 'EdgeColor', 'r')
legend('Theory', 'Experiment')


% Qn 11
x = 1:0.01:10;

subplot(2, 2, 1);
plot(x, x.^2)
subplot(2, 2, 2);
plot(x, x.^3)
subplot(2, 2, 3);
plot(x, log10(x))
subplot(2, 2, 4);
plot(x, 1./x)


% Qn 12
y = @(x) (x+1)*(x-2)*(2*x - 0.25) - exp(x);

fplot(y, [0 3])
figure()
fplot(y, [-3 6])




