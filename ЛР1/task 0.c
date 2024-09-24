#include <stdio.h>
#include <stdlib.h>

struct Point {
    int index;
    double mass;
    double x, y;  // Координати, якщо потрібно
};

void mergePoints(struct Point* points, int index1, int index2) {
    // Об’єднати точки[index1] і точки[index2]
    points[index1].mass += points[index2].mass;
    points[index2].mass = 0;  // Позначити об'єднану точку як вилучену
}

int findClosestPoint(struct Point* points, int n, int currentPoint) {
    int closestPoint = -1;
    double minDistance = -1;

    for (int i = 0; i < n; ++i) {
        if (i != currentPoint && points[i].mass > 0) {
            double distance = sqrt(pow(points[i].x - points[currentPoint].x, 2) + pow(points[i].y - points[currentPoint].y, 2));
            if (closestPoint == -1 || distance < minDistance) {
                closestPoint = i;
                minDistance = distance;
            }
        }
    }

    return closestPoint;
}

int findLastPoint(struct Point* points, int n) {
    int lastPoint = -1;

    for (int i = 0; i < n; ++i) {
        if (points[i].mass > 0) {
            if (lastPoint == -1) {
                lastPoint = i;
            } else {
                // Якщо є більше однієї точки з масою, то процес не завершено
                return -1;
            }
        }
    }

    return lastPoint;
}

int main() {
    int n;
    printf("Enter the number of material points: ");
    scanf("%d", &n);

    struct Point* points = (struct Point*)malloc(n * sizeof(struct Point));

   // Ініціалізація точок масами
    for (int i = 0; i < n; ++i) {
        points[i].index = i;
        printf("Enter the mass for point %d: ", i + 1);
        scanf("%lf", &points[i].mass);
    }

    while (1) {
        int currentPoint = -1;
        double minMass = -1;

        // Знайти точку з найменшою масою
        for (int i = 0; i < n; ++i) {
            if (points[i].mass > 0 && (currentPoint == -1 || points[i].mass < minMass)) {
                currentPoint = i;
                minMass = points[i].mass;
            }
        }

        // Якщо залишилася лише одна точка, розірвати цикл
        if (findLastPoint(points, n) != -1) {
            break;
        }

        // Знайти точку, найближчу до поточної точки
        int closestPoint = findClosestPoint(points, n, currentPoint);

        // Об’єднати поточну точку з найближчою
        mergePoints(points, currentPoint, closestPoint);
    }

    // Знайти та вивести останню точку, що залишилася
    int lastPoint = findLastPoint(points, n);
    printf("The last remaining point is %d\n", lastPoint + 1);

    free(points);

    return 0;
}
