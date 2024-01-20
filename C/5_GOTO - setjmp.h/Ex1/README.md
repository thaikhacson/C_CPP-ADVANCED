**EX1: Cải Tiến Hàm THROW**

**_Mục tiêu:_**

- Sửa đổi hàm THROW để nó chấp nhận một thông điệp lỗi dưới dạng chuỗi ký tự, bên cạnh mã lỗi.
- Thông điệp lỗi nên được lưu trữ ở một nơi mà có thể truy cập được sau khi longjmp được gọi.

**_Yêu cầu:_**

- Sửa đổi hàm THROW trong chương trình C mẫu đã cho.
- Hàm THROW phải có khả năng nhận một thông điệp lỗi dưới dạng chuỗi ký tự và một mã lỗi.
- Thông điệp lỗi và mã lỗi phải được lưu trữ sao cho có thể được truy xuất từ khối CATCH.
- Viết hàm hoặc các hàm thử nghiệm khác, mỗi hàm ném ra một loại lỗi khác nhau, sử dụng cải tiến hàm THROW.
- Trong hàm main, xử lý các lỗi này một cách riêng biệt, in ra thông điệp lỗi tương ứng cho mỗi loại lỗi.

**_Ví dụ:_**

Thay vì bạn sử dụng đoạn mã sau:

```
double divide(int a, int b) {
   if (b == 0) {
       THROW(1); // Sử dụng mã lỗi 1 cho lỗi chia cho 0
   }
   THROW(2); //Những lỗi khác
   return (double)a / b;
}
```
Được thay thế bằng:

```
double divide(int a, int b) {
   if (b == 0) {
       THROW(1, "Lỗi: Phép chia cho 0!"); // Sử dụng mã lỗi 1 cho lỗi chia cho 0
   }
   THROW(2, "Lỗi: Những lỗi khác!");
   return (double)a / b;
}
```

Trong ví dụ này, mã lỗi 1 có thể tượng trưng cho lỗi chia cho 0, và chuỗi "Lỗi: Phép chia cho 0!" là thông điệp lỗi tương ứng. Sau khi gọi THROW, khối CATCH(1) trong main sẽ xử lý lỗi này và in ra thông điệp lỗi.

Thay vì bạn sử dụng đoạn mã sau:

```
CATCH(1) {
       printf("Lỗi: Phép chia cho 0!\n");
}CATCH(2) {
       printf("Lỗi: Những lỗi khác!\n");
   }
```

Được thay thế bằng:

```
CATCH(1) {
       printf("%s\n", error_code)
}CATCH(2) {
       printf("%s\n", error_code)
}
```

