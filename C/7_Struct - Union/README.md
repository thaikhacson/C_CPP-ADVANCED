 **Struct vs Union**

Struct và Union là 2 kiểu dữ liệu User-defined (Người dùng tự định nghĩa) trong C, là kiểu dữ liệu chứa các thành phần dữ liệu khác bên trong.
 
Hai kiểu dữ liệu này được sử dụng khá phổ biến trong các thư viện cho vi điều khiển (ví dụ thư viện STD STM32), và quản lý sự kiện trong các ứng dụng nhúng, IOT.

**A.	 Về đặc điểm thì khác nhau rõ ràng nhất là việc chiếm dụng bộ nhớ**
 
![image](https://github.com/sondt308/HomeWork/assets/143014005/35f973a7-aa62-493a-83ff-21ef5aab2098)

**1.**	**Dữ liệu của các thành viên của Struct được lưu trữ ở những vùng nhớ khác nhau, có thể tuân theo nguyên tắc padding.**
   
 => Memory sử dụng lớn hơn hoặc bằng tổng kích thước các thành phần.
Để hiểu rõ về việc này, chúng ta hãy cùng tìm hiểu sơ qua Data Structure Alignment & Padding.

Data structure alignment là gì? Nó hoạt động như thế nào? Lâu lâu chúng ta vẫn hay nghe software này không tương thích với hệ điều hành 64bit hay software này chỉ chạy trên HĐH 32bit gì đó, vậy liên quan gì tới data structure alignment không?

Bên cạnh đó chúng ta cần một số kiến thức nền về hệ thống để có thể hiểu sâu hơn. Mình sẽ cung cấp cho các bạn trong bài viết này (nhưng chỉ là tổng quan thôi, vì nó khá là chuyên sâu, nếu có thời gian mình sẽ viết thêm những bài về nó) và mình sẽ cung cấp keyword để các bạn có thể tra google thêm.

**_1.1.	Data Structure Alignment là gì?_**

Theo Wikipedia: Data Structure is the way data is arranged and accessed in computer memory. Có nghĩa là khi data load lên memory sẽ được CPU sắp xếp lại để tiện cho việc truy xuất tối ưu nhất có thể.

Chúng ta đều biết rằng các CPU hiện đại của chúng ta luôn thao tác trên memory theo từng khối ở địa chỉ là một số chẵn, không thể thao tác trên địa chỉ là số lẻ được. Như vậy với mstruct của chúng ta, ví dụ biến “char c” nằm trên memory có địa chỉ chẵn, nếu biến “int i” nằm kế tiếp thì sẽ có địa chỉ lẻ rất phức tạp để CPU thao tác với biến “int i” này. Vì vậy chúng ta có thêm 2 khái niệm sau:
•	Data alignment: sắp xếp data sao cho địa chỉ của các biến luôn là số chẵn và phù hợp với hệ thống
•	Data padding: để làm được việc alignment như ở trên chúng ta cần phải “padding” thêm một số byte vào sau biến “char c” để khi đó biến “int i” có thể ở địa chỉ chẵn

**_1.2.	Sau đây mình sẽ giới thiệu thêm về hệ thống_**
•	Trên các hệ thống khác nhau, chúng ta sẽ có sự khác nhau giữa size của các data type như sau:
•	Lúc nãy ở trên chúng ta có biết được rằng CPU chỉ thao tác trên memory theo từng khối ở địa chỉ chẵn. Hay nói chính xác hơn khối ở đây là 1 WORD size. Tùy thuộc vào kiến trúc của CPU, nhưng thông dụng nhất có các size như sau:

o	Trên system 16bit: 1 WORD = 16bit = 2 bytes

o	Trên system 32bit: 1 WORD = 32bit = 4 bytes

o	Trên system 64bit: 1 WORD = 64bit = 8 bytes

•	N-byte alignment: chúng ta có các loại n-byte alignment: 2-byte align, 4-byte align, 8-byte align.

**_1.3.	Cách tính kích thước bộ nhớ_**

-	Align theo kiểu dữ liệu có kích thước lớn nhất. Tức là một cách để sắp xếp các thành viên trong một struct sao cho địa chỉ của chúng bắt đầu từ một số nguyên chia hết cho kích thước của kiểu dữ liệu có kích thước lớn nhất trong struct đó. Điều này giúp cho CPU có thể truy cập vào các thành viên của struct một cách hiệu quả hơn.
-	Kiểu dữ liệu chỉ có thể đặt ở ô nhớ có vị trí chia hết cho chính nó
-	Ví dụ kiểu int (4 byte) thì đặt tại địa chỉ chia hết cho 4 là: 4, 8, 12,...
-	Còn kiểu char (1 byte) thì đặt ở bất kì ô nhớ nào, thường sẽ đặt liền kề với địa chỉ của biến trước đó


**2. Dữ liệu của các thành viên trong Union được lưu trữ trong cùng 1 vùng nhớ.**
    
=> Memory sử dụng = Kích thước thành viên lớn nhất.

**B.	Về mặt ứng dụng thì rõ ràng nhiều trường hợp có thể dùng Struct thay cho Union vì nó bao quát và tường minh hơn.**

**C.	Nhưng trong các ứng dụng lớn, có nhiều sự kiện, thì việc dùng Union sẽ giúp tiết kiệm bộ nhớ hơn rất nhiều (Đặc biệt với ứng dụng sử dụng Vi điều khiển có bộ nhớ hạn chế).**

**D.	Một ứng dụng khác mình dùng Union là quản lý các thanh ghi trong vi điều khiển (STM32).**

