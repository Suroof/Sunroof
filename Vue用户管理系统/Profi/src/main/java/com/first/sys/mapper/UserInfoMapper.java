package com.first.sys.mapper;

import com.first.sys.entity.UserInfo;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;
@Mapper
public interface UserInfoMapper {
//    insert、update 和 delete 操作返回的是整数，表示受影响的行数。
    List<UserInfo> selectAll();
    UserInfo selectById(Long id);
    int insert(UserInfo userInfo);
    int update(UserInfo userInfo);
    int delete(Long id);
    UserInfo selectByUsernameAndPassword(String username, String password);

    List<UserInfo> selectList(Object o);

}
