# IP_Deconvolution
Using wiener filter to denoise blurred image and blurred & Gaussain noised image
- C++ / OpenCV 사용
- PSF kernel normalization
- DFT를 이용한 영상 및 kernel의 주파수 영역 변환
- Wiener Filter를 이용한 Deconvolution 구현
- Blur 및 Gaussian noise가 포함된 영상 복원
- Noise 수준에 따른 K 값 조절 및 결과 비교

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




