package com.first;

import com.first.sys.entity.UserInfo;
import com.first.sys.mapper.UserInfoMapper;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import javax.annotation.Resource;
import java.util.List;

@SpringBootTest
class ProfiApplicationTests {
    @Resource
    private UserInfoMapper userInfoMapper;

    @Test
    void testMapper(){
        List<UserInfo> userInfos = userInfoMapper.selectList(null);
        userInfos.forEach(System.out::println);
    }

}
