**EX2: Xử Lý Nhiều Loại Lỗi Trong Hệ Thống Phức Tạp Sử Dụng Macro TRY-CATCH**

**_Mục Tiêu:_**

Viết một chương trình trong ngôn ngữ C sử dụng các macro TRY, CATCH, và THROW để mô phỏng việc xử lý nhiều loại lỗi trong một hệ thống phức tạp.

**_Yêu Cầu:_**

- Định nghĩa các macro TRY, CATCH, và THROW giúp xử lý lỗi trong chương trình.
- Tạo các hàm giả lập các hoạt động khác nhau, mỗi hàm có khả năng "ném" ra một loại lỗi cụ thể sử dụng macro THROW.
- Trong hàm main, gọi các hàm này trong một khối TRY và xử lý các lỗi tương ứng trong các khối CATCH phù hợp.
- Các loại lỗi có thể bao gồm nhưng không giới hạn ở: lỗi đọc file, lỗi xử lý mạng, lỗi tính toán dữ liệu.
- In ra thông báo lỗi phù hợp khi một lỗi được bắt và xử lý.

**_Mô Tả Chi Tiết Hơn:_**

- Bạn cần viết ba hàm mô phỏng ba hoạt động khác nhau: readFile, networkOperation, và calculateData.
- Mỗi hàm này sẽ sử dụng THROW để ném ra một loại lỗi cụ thể khi gặp sự cố.
- Trong main, sử dụng TRY để bao quanh việc gọi các hàm này và sử dụng các khối CATCH để xử lý từng loại lỗi riêng biệt.
- Mỗi khối CATCH sẽ in ra một thông báo lỗi đặc trưng cho lỗi tương ứng.
- Đảm bảo chương trình kết thúc một cách an toàn, in ra thông báo kết thúc chương trình sau khi tất cả các lỗi đã được xử lý.

Cho một enum lưu các mã lỗi như sau: 

`enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR };`

Thông tin các hàm:

```
void readFile() {
    printf("Đọc file...\n");
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}

void networkOperation() {
    // Bổ sung chương trình
}

void calculateData() {
   // Bổ sung chương trình
}
```

Chương trình trong hàm main:

```
TRY {
        readFile();
        networkOperation();
        calculateData();
    } CATCH(FILE_ERROR) {
        printf("%s\n", error_message);} // Bổ sung thêm nhiều CATCH

```

