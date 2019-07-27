# Project Library Management (console C/C++)

Giáo Viên: Lưu Nguyễn Kỳ Thư

### Thư viện
 
* Ta tổ chức các danh sách sau:  
 1. Đầu sách : danh sách tuyến tính là 1 **_mảng con trỏ_** (**ISBN** , *Tên sách*, *Số trang*, *Tác giả*, *năm xuất bản*, *thể loại*, *con trỏ dms*): con trỏ sẽ trỏ đến các sách thuộc đầu sách tương ứng 
 2. Danh mục sách : **_danh sách liên kết đơn_**( **Mã sách**,  *trạng thái*, *vị trí*). Mỗi cuốn sách chỉ có 1 mã duy nhất; trạng thái của sách bao gồm: **0**: cho mượn được, **1**: đã có độc giả mượn, **2**: sách đã thanh lý .  
 3. Danh sách thẻ độc giả: **_cây nhị phân tìm kiếm_** (**MATHE** (số nguyên ngẫu nhiên tự động), *Ho*, *Te*n,  *Phai*, *trạng thái của thẻ*, *con trỏ*): con trỏ sẽ trỏ đến danh sách các cuốn sách đã và đang mượn. 
 4. Danh sách MUONTRA : **_danh sách liên kết kép_** ( **MASACH**,  *NgayMuon*, *NgayTra*, *trạng thái*): trạng thái =**0** là sách đang mượn (chưa trả), =**1** là đã trả, =**2** : làm mất sách  
 
* Chương trình có các chức năng sau:  
 1. Nhập thẻ độc giả: *thêm* / *xóa* / *hiệu chỉnh* thông tin thẻ độc giả. Mã thẻ độc giả được chương trình *tự động lấy ngẫu nhiên* và *không trùng với các mã thẻ độc giả cũ*; Phái chỉ nhận **‘Nam’** hoặc **‘Nữ’**; trạng thái thẻ = **0** khi thẻ bị khóa, trạng thái thẻ = **1** khi thẻ  đang hoạt động (được quyền mượn sách).  
 2. In danh sách độc giả : in ra màn hình theo thứ tự *tên*+*họ* tăng dần hoặc theo thứ tự mã độc giả **tăng dần** theo yêu cầu của thủ thư. 
 3. Nhập thông tin đầu sách và *đánh mã sách tự động* 
 4. In danh sách các đầu sách trong thư viện theo từng *thể loại*, trong từng thể loại thì in theo thứ tự *tên sách tăng dần*. 
 5. Tìm thông tin sách dựa vào *tên sách* : in ra các thông tin mã **ISBN**, *tên sách*, *tác giả*, *năm xuất bản*, *thể loại*, *các mã sách* , *trạng thái* mã sách trong thư viện. 
 6. Mượn sách : nhập vào *mã thẻ độc giả*, chương trình sẽ liệt kê các sách mà độc giả đang mượn. Mỗi độc giả chỉ được **mượn tối đa 3 cuốn**, không cho mượn khi giữ 1 sách **quá hạn** (7 ngày) 
 7. Trả sách 
 8. Liệt kê danh sách các sách mà 1 độc giả đang mượn 
 9. In danh sách độc giả mượn sách quá hạn theo thứ tự *thời gian quá hạn giảm dần* 
 10. In 10 sách có số lượt mượn *nhiều nhất*. 
 