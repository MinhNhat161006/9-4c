#include <stdio.h>

int main() {
    int arr[100], currentLength = 0, choice;

    while (1) {
        // Hiển thị menu
        printf("\nMENU\n");
        printf("1. Nhập vào mảng\n");
        printf("2. Hiển thị mảng\n");
        printf("3. Thêm phần tử\n");
        printf("4. Sửa phần tử\n");
        printf("5. Xóa phần tử\n");
        printf("6. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        if (choice == 6) break;

        switch (choice) {
            case 1: { // Nhập vào mảng
                printf("Nhập số phần tử muốn nhập (tối đa 100): ");
                scanf("%d", &currentLength);

                if (currentLength < 0 || currentLength > 100) {
                    printf("Số phần tử không hợp lệ.\n");
                    currentLength = 0;
                } else {
                    printf("Nhập các phần tử:\n");
                    for (int i = 0; i < currentLength; i++) {
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            }
            case 2: { // Hiển thị mảng
                if (currentLength == 0) {
                    printf("Mảng trống.\n");
                } else {
                    printf("Mảng hiện tại: ");
                    for (int i = 0; i < currentLength; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: { // Thêm phần tử
                if (currentLength >= 100) {
                    printf("Mảng đã đầy, không thể thêm phần tử.\n");
                } else {
                    int addValue, addIndex;
                    printf("Nhập giá trị muốn thêm: ");
                    scanf("%d", &addValue);
                    printf("Nhập vị trí muốn thêm (0-%d): ", currentLength);
                    scanf("%d", &addIndex);

                    if (addIndex < 0 || addIndex > currentLength) {
                        printf("Vị trí không hợp lệ.\n");
                    } else {
                        for (int i = currentLength; i > addIndex; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[addIndex] = addValue;
                        currentLength++;
                    }
                }
                break;
            }
            case 4: { // Sửa phần tử
                int index, newValue;
                printf("Nhập vị trí cần sửa (0-%d): ", currentLength - 1);
                scanf("%d", &index);

                if (index < 0 || index >= currentLength) {
                    printf("Vị trí không hợp lệ.\n");
                } else {
                    printf("Nhập giá trị mới: ");
                    scanf("%d", &newValue);
                    arr[index] = newValue;
                }
                break;
            }
            case 5: { // Xóa phần tử
                int deleteIndex;
                printf("Nhập vị trí cần xóa (0-%d): ", currentLength - 1);
                scanf("%d", &deleteIndex);

                if (deleteIndex < 0 || deleteIndex >= currentLength) {
                    printf("Vị trí không hợp lệ.\n");
                } else {
                    for (int i = deleteIndex; i < currentLength - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    currentLength--;
                }
                break;
            }
            default:
                printf("Lựa chọn không hợp lệ.\n");
        }
    }

    printf("Chương trình đã thoát.\n");
    return 0;
}
