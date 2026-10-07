# IP_Deconvolution
point spread  function 이미지를 blur kernel로 사용하여 Blur 된 이미지를 Winer Filter로 복원하는 Deconvolution
# Blur kernel
- 이미지에 적용된 blur의특성을 나타내는 point spread function으로 사용.
- 픽셀 값을 전체 합이 1이 되도록 정규화.
- DFT 해서 각 주파수 성분이 얼마나 blur에 영향을 받는지로 변환. 
# DFT
- 공간에서 blur는 convolution 연산이지만, 주파수 영역에서는 단순 곱셉으로 표현이 가능.
- DFT를 이용해 주파수 영역으로 변환하여 deconvolution을 효율적으로 수행
# Deconvolution
- Blur 과정에서 곱해진 point spread function의 영향을 역으로 제거하여 원본 영상의 주파수 성분을 복원
- 하지만 단순 PSF로 나누는 방식은 PSF가 0에 가까울 경우 noise까지 커질 수 있음.
# Wiener filter
- noise 커지는 것을 방지하기 위해 사용
- 분모에 k 값을 추가하여 blur kernel 값이 작은 주파수에서 복원값이 커지는것을 막는다.

# Wiener filter

<img width="256" height="256" alt="Wiener_Kernel" src="https://github.com/user-attachments/assets/ca9d06e2-f455-40a6-a1a4-2685ffe74fcb" />

# blurred only

<img width="256" height="256" alt="Wiener_Input1" src="https://github.com/user-attachments/assets/bafb5a6d-fd6f-4643-bbb0-dff89dc56c13" /> 

# restored

<img width="256" height="256" alt="KakaoTalk_20261007_144007293" src="https://github.com/user-attachments/assets/d1014fb6-28a3-4e4b-8cbb-5738038da977" />


# blurred & gasussian noise

<img width="256" height="256" alt="Wiener_Input2" src="https://github.com/user-attachments/assets/c99ee2a0-2183-4015-87d7-5630670d484b" />

# restored

<img width="256" height="256" alt="KakaoTalk_20261007_144007293_01" src="https://github.com/user-attachments/assets/3a6720f6-e365-4d11-8b2b-23fa053f4049" />




# result




